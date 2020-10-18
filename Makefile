BIN=../gbdk-n/bin
BUILD=./build

SOURCES := $(shell find src -type f -name '*.c')

build: $(SOURCES)
	mkdir -p $(BUILD)
	$(BIN)/gbdk-n-compile.sh $(SOURCES) -o $(BUILD)/output.rel
	$(BIN)/gbdk-n-link.sh $(BUILD)/output.rel -o $(BUILD)/output.ihx
	$(BIN)/gbdk-n-make-rom.sh $(BUILD)/output.ihx $(BUILD)/output.gb

clean:
	rm -rf $(BUILD)

run: build
	mgba build/output.gb

.PHONY: build
