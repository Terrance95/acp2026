#!/usr/bin/env bats

setup() {
    # Windows Safety
    taskkill //F //IM demo9.exe //T 2> /dev/null || true
    gcc -g demo9.c -o demo9.exe
    # Clean up old data files before each test
    rm -f students.txt
}

teardown() {
    rm -f demo9.exe
    rm -f students.txt
}

@test "Test 1: Full Cycle - Input, Save, and Read" {
    # Simulating: 2 students
    # Student 1: ID 101, Name 'Terrance', Marks 95.5
    # Student 2: ID 102, Name 'Paul', Marks 88.0
    run bash -c "printf '2\n101 Terrance 95.5\n102 Paul 88.0\n' | ./demo9.exe"
    
    [ "$status" -eq 0 ]
    
    # 1. Check Terminal Output
    [[ "$output" == *"ID: 101, Name: Terrance, Marks: 95.50"* ]]
    [[ "$output" == *"ID: 102, Name: Paul, Marks: 88.00"* ]]
    
    # 2. Check File Existence
    [ -f "students.txt" ]
    
    # 3. Check File Content (ensuring it matches the expected format)
    run cat students.txt
    [[ "$output" == *"101 Terrance 95.500000"* ]]
}

@test "Test 2: Zero Students Case" {
    run bash -c "printf '0\n' | ./demo9.exe"
    
    [ "$status" -eq 0 ]
    # The file should still be created (empty) or the program should exit gracefully
    [[ "$output" == *"Student Records from File:"* ]]
}

@test "Test 3: File Integrity (Single Entry)" {
    run bash -c "printf '1\n1 Alpha 100\n' | ./demo9.exe"
    
    [ "$status" -eq 0 ]
    # Check if the file is precisely 1 line long
    line_count=$(wc -l < students.txt)
    [ "$line_count" -eq 1 ]
}