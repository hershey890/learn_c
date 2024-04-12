CC = gcc-12
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -pthread -g

SRC_DIR = .
BUILD_DIR = build
EXECUTABLES = $(patsubst $(SRC_DIR)/%.c,$BUILD_DIR/%,$(wildcard $(SRC_DIR)/*.c)) 

# all: $(EXECUTABLES)

#$(BUILD_DIR)/%: $(BUILD_DIR)/%.o | $(BUILD_DIR)
#	$(CC) $(LDFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)/$@	

clean:
	@rm -rf $(BUILD_DIR)/*
