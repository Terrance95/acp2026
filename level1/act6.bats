#!/usr/bin/env bats

setup() {
    # Windows Process Safety: Kill any hung instances of act6.exe
    taskkill //F //IM act6.exe //T 2> /dev/null || true
    gcc -g act6.c -o act6.exe
}

teardown() {
    rm -f act6.exe || true
}

@test "Requirement 1: Basic String Swap" {
    # Testing standard input swap
    run bash -c "printf 'FirstWord\nSecondWord\n' | ./act6.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"First string: SecondWord"* ]]
    [[ "$output" == *"Second string: FirstWord"* ]]
}

@test "Requirement 2: Handling Spaces (The fgets Test)" {
    # If this fails, you are likely using scanf("%s") instead of fgets
    run bash -c "printf 'Terrance Paul\nREVA University\n' | ./act6.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"First string: REVA University"* ]]
    [[ "$output" == *"Second string: Terrance Paul"* ]]
}

@test "Requirement 3: Empty Input Resilience" {
    # One string is just a newline, the other is 'Data'
    run bash -c "printf '\nData\n' | ./act6.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"First string: Data"* ]]
    # Second string should be empty/blank
    [[ "$output" == *"Second string: "* ]]
}

@test "Requirement 4: Max Boundary Stability" {
    # Send exactly 99 'a's to test 100-char buffer limit
    long_input=$(printf 'a%.0s' {1..99})
    run bash -c "printf '$long_input\nShort\n' | ./act6.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"First string: Short"* ]]
    [[ "$output" == *"Second string: $long_input"* ]]
}