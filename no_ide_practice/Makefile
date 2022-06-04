# Hints.
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))
current_abs_dir := $(abspath $(CURDIR))

%: %.cpp
	$(info $(mkfile_path))
	$(info $(current_dir))
	$(info $(current_abs_dir))
	cd $(abspath $(dir $<)) && \
		mkdir -p bin && \
		g++ --std=c++20 -g $(abspath $(lastword $<)) -o bin/$(notdir $@) && \
		cd $(CURDIR)

%: %.py
	$(info $(mkfile_path))
	$(info $(current_dir))
	$(info $(current_abs_dir))
	cd $(abspath $(dir $<)) && \
		python3 $(abspath $(lastword $<)) && \
		cd $(CURDIR)
