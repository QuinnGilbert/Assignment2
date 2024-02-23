# Assignment2

## Part 1
One guest (guest 0) acts as the "counter" and will count the other n-1 guests. This guest will count the number of times it finds the cupcake eaten, and also replenish the cupcake if it is eaten. All of the other guests will eat the cupcake only once (the first time they can) if it is available and do nothing otherwise. This way, guest 0 will know that once he finds the cupcake eaten n-1 times each guest has been in the room at least once. This idea is guaranteed to work, but it can end up being slow for a large amount of guests.

## Part 2
The first strategy is not mutually exclusive and can result in many issues. The second strategy ensures that only one guest can enter at a time, however it does not ensure that guests can enter fairly, as the guest that enters will essentially be random, meaning that some guests might not ever enter at all. The third strategy ensures that the guests are fairly and safely queued to enter one at a time in the order that they leave.