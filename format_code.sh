#!/bin/bash
find src include test -type f -name "*.[ch]pp" -exec clang-format -i {} +