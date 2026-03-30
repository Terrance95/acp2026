#!/usr/bin/env bats

# 1. Standard Case: Diverse floating point numbers
@test "1. Standard: High/Low with decimals" {
  run bash -c "echo -e '3\n25.5\n30.05\n15.45' | ./act1"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Highest temperature: 30.05"* ]]
  [[ "$output" == *"Lowest temperature: 15.45"* ]]
}

# 2. Edge Case: All temperatures are the same
@test "2. Edge: All temperatures identical" {
  run bash -c "echo -e '2\n21.0\n21.0' | ./act1"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Highest temperature: 21.00"* ]]
  [[ "$output" == *"Lowest temperature: 21.00"* ]]
}

# 3. Edge Case: Negative values (Testing number line logic)
@test "3. Edge: Only negative temperatures" {
  run bash -c "echo -e '3\n-10.5\n-5.2\n-20.0' | ./act1"
  [ "$status" -eq 0 ]
  [[ "$output" == *"Highest temperature: -5.20"* ]]
  [[ "$output" == *"Lowest temperature: -20.00"* ]]
}

# 4. Error Case: N is Zero (Triggers your first validation)
@test "4. Error: N is zero" {
  run bash -c "echo -e '0' | ./act1"
  [ "$status" -eq 1 ]
  [[ "$output" == *"invalid value for n entered"* ]]
}

# 5. Error Case: Non-numeric input for N
@test "5. Error: Alphabetical input for N" {
  run bash -c "echo -e 'abc' | ./act1"
  [ "$status" -eq 1 ]
  [[ "$output" == *"invalid value for n entered"* ]]
}