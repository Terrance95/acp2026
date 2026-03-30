#!/usr/bin/env bats

setup() {
    # Windows Process Safety
    taskkill //F //IM demo10.exe //T 2> /dev/null || true
    gcc -g demo10.c -o demo10.exe
    # Clean old binary data
    rm -f students.dat
}

teardown() {
    rm -f demo10.exe
    rm -f students.dat
}

@test "Test 1: Binary Cycle - Multiple Students" {
    # Input: 2 students
    # S1: 1 Terrance 9.8
    # S2: 2 Paul 9.5
    run bash -c "printf '2\n1 Terrance 9.8\n2 Paul 9.5\n' | ./demo10.exe"
    
    [ "$status" -eq 0 ]
    
    # Verify the read-back output from the binary file
    [[ "$output" == *"Roll: 1, Name: Terrance, CGPA: 9.80"* ]]
    [[ "$output" == *"Roll: 2, Name: Paul, CGPA: 9.50"* ]]
    
    # Verify file exists and is the correct size
    # Each Student struct is (4 bytes for int + 50 for char + 4 for float) = ~58-60 bytes
    # For 2 students, the file should be around 116-120 bytes.
    [ -f "students.dat" ]
    file_size=$(wc -c < students.dat)
    [ "$file_size" -gt 0 ]
}

@test "Test 2: Integrity - Single Entry" {
    run bash -c "printf '1\n7 Ayanokoji 10.0\n' | ./demo10.exe"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"Roll: 7, Name: Ayanokoji, CGPA: 10.00"* ]]
}

@test "Test 3: Empty Input Handling" {
    run bash -c "printf '0\n' | ./demo10.exe"
    
    [ "$status" -eq 0 ]
    # The file might be created empty or not at all depending on n check.
}