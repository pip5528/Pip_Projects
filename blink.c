#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

struct gpiod_chip *chip;
struct gpiod_line_settings *line_set;
struct gpiod_line_config *line_cfg;
struct gpiod_line_request *line_req;
struct gpiod_info_event *event;

int main(void) {


const unsigned int offset = 17;

// I think I'm starting to get the hang of the general structure of libgpiod 2.2 if I'm being honest.

// TODO: Add additional functionality such as different cycles

chip = gpiod_chip_open("/dev/gpiochip0");

if(!chip) {
    perror("Failed to open chip!\n");
    return -1;
}

// Shoutout to Codex for additional error checking as well as telling me what order to release in.

line_set = gpiod_line_settings_new();
if (!line_set) {
    perror("gpiod_line_settings_new");
    goto close_chip;
}

gpiod_line_settings_set_direction(line_set, GPIOD_LINE_DIRECTION_OUTPUT);
if (gpiod_line_settings_set_direction (line_set, GPIOD_LINE_DIRECTION_OUTPUT) < 0) {
    perror("setting direction");
    goto free_settings;
}



gpiod_line_settings_set_output_value(line_set, GPIOD_LINE_VALUE_INACTIVE);
if (gpiod_line_settings_set_output_value(line_set, GPIOD_LINE_VALUE_INACTIVE) < 0) {
    perror("setting initial value");
    goto free_settings;
}

line_cfg = gpiod_line_config_new();
if (!line_cfg) {
    perror("gpiod_line_config_new");
    goto free_settings;
}

gpiod_line_config_add_line_settings(line_cfg, &offset, 1, line_set);
if (gpiod_line_config_add_line_settings(line_cfg, &offset, 1, line_set) < 0) {
    perror("adding line settings");
    goto free_config;
}



line_req = gpiod_chip_request_lines(chip, NULL, line_cfg);
if (!line_req) {
    perror("requesting GPIO line");
    goto free_config;
}


while(1) {
    if (gpiod_line_request_set_value(line_req, offset, GPIOD_LINE_VALUE_ACTIVE) < 0) {
        perror("setting GPIO active");
        break;
    }
    usleep(100000);
    if (gpiod_line_request_set_value(line_req, offset, GPIOD_LINE_VALUE_INACTIVE) < 0) {
        perror("setting GPIO inactive");
        break;
    }
    usleep(100000);
}

gpiod_line_request_release(line_req);
free_config:
gpiod_line_config_free(line_cfg);
free_settings:
gpiod_line_settings_free(line_set);
close_chip:
gpiod_chip_close(chip);

return 0;
}
