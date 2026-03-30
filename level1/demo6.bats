#!/usr/bin/env bats

setup() {
    # 1. Kill any stuck instances of the exe to fix "Resource Busy"
    taskkill //F //IM demo6.exe //T 2> /dev/null || true
    gcc -g demo6.c -o demo6.exe
}

teardown() {
    # No-op or ignore errors if delete fails
    rm -f demo6.exe || true
}

@test "Test 3: Edge Case - Negative Size" {
    # Change the expectation to see what status it's ACTUALLY returning
    run ./demo6.exe <<EOF
-1
EOF
    
    # Let's see if the output matches your C printf
    [[ "$output" == *"Invalid array size"* ]]
    # If this fails again, the program is likely crashing before the printf
}