CC = gcc-12
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -pthread

SRC_DIR = .
BUILD_DIR = build
EXECUTABLES = $(patsubst $(SRC_DIR)/%.c,$BUILD_DIR/%,$(wildcard $(SRC_DIR)/*.c)) 

all: $(EXECUTABLES)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	@rm -rf $(BUILD_DIR)
