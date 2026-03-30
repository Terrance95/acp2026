#!/usr/bin/env bats

setup() {
    # Windows Process Safety
    taskkill //F //IM demo8.exe //T 2> /dev/null || true
    gcc -g demo8.c -o demo8.exe
}

teardown() {
    rm -f demo8.exe || true
}

@test "Test 1: Standard Concatenation" {
    # Testing 'Hello' + 'World'
    run bash -c "printf 'Hello\nWorld\n' | ./demo8.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Concatenated string: HelloWorld"* ]]
}

@test "Test 2: Concatenation with Spaces" {
    # Testing 'NAOS ' + 'Project'
    run bash -c "printf 'NAOS \nProject\n' | ./demo8.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Concatenated string: NAOS Project"* ]]
}

@test "Test 3: First String Empty" {
    # Testing '' + 'Logic'
    run bash -c "printf '\nLogic\n' | ./demo8.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Concatenated string: Logic"* ]]
}

@test "Test 4: Second String Empty" {
    # Testing 'Kernel' + ''
    run bash -c "printf 'Kernel\n\n' | ./demo8.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Concatenated string: Kernel"* ]]
}

@test "Test 5: Both Strings Empty" {
    run bash -c "printf '\n\n' | ./demo8.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Concatenated string: "* ]]
}