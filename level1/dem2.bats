#!/usr/bin/env bats

setup() {
    gcc demo2.c -o demo2
}

@test "Test 1: Standard case" {
  run ./demo2 <<EOF
Alpha 5.0 4.0
Beta 10.0 3.0
Gamma 2.0 2.0
EOF
  [ "$status" -eq 0 ]
  [[ "$output" == *"Area of Alpha:20.00"* ]]
}

@test "Test 2: Equal Areas" {
  run ./demo2 <<EOF
RectA 10.0 10.0
RectB 20.0 5.0
RectC 1.0 1.0
EOF
  [ "$status" -eq 0 ]
  [[ "$output" == *"Two or more rectangles have equal largest area"* ]]
}

@test "Test 3: Zero Dimensions" {
  run ./demo2 <<EOF
Ghost 0.0 5.0
Point 0.1 0.1
Void 0.0 0.0
EOF
  [ "$status" -eq 0 ]
  [[ "$output" == *"Area of Point:0.01"* ]]
}

@test "Test 4: Large Values" {
  run ./demo2 <<EOF
Big 1000.5 1000.0
Small 1.0 1.0
Med 500.0 500.0
EOF
  [ "$status" -eq 0 ]
  [[ "$output" == *"Area of Big:1000500.00"* ]]
}

@test "Test 5: Name Length" {
  run ./demo2 <<EOF
SuperLongNameTest 2.0 2.0
Short 5.0 5.0
Thin 10.0 0.5
EOF
  [ "$status" -eq 0 ]
  [[ "$output" == *"Area of SuperLongNameTest:4.00"* ]]
}