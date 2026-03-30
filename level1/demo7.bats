#!/usr/bin/env bats

setup() {
    # Taskkill is our "Windows Safety" to prevent 'Resource Busy' errors
    taskkill //F //IM demo7.exe //T 2> /dev/null || true
    gcc -g demo7.c -o demo7.exe
}

teardown() {
    rm -f demo7.exe || true
}

@test "Test 1: Identical Strings" {
    run bash -c "printf 'hello\nhello\n' | ./demo7.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Strings are equal"* ]]
    [[ "$output" == *"(Result: 0)"* ]]
}

@test "Test 2: First String Greater (Alphabetical)" {
    # 'zebra' comes after 'apple'
    run bash -c "printf 'zebra\napple\n' | ./demo7.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"First string is greater"* ]]
    [[ "$output" == *"(Result: 1)"* ]]
}

@test "Test 3: Second String Greater (Alphabetical)" {
    # 'apple' comes before 'banana'
    run bash -c "printf 'apple\nbanana\n' | ./demo7.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Second string is greater"* ]]
    [[ "$output" == *"(Result: -1)"* ]]
}

@test "Test 4: Empty String Comparison" {
    # Testing how it handles just pressing 'Enter' for both
    run bash -c "printf '\n\n' | ./demo7.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Strings are equal"* ]]
}

@test "Test 5: Case Sensitivity Check" {
    # 'Apple' (65) vs 'apple' (97) - ASCII check
    run bash -c "printf 'Apple\napple\n' | ./demo7.exe"
    
    [ "$status" -eq 0 ]
    # In ASCII, 'A' is 65 and 'a' is 97, so 'apple' is greater.
    [[ "$output" == *"Second string is greater"* ]]
}