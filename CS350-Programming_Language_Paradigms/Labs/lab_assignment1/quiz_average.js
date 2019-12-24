'use strict';
function average (n,q1,q2,q3){
    let result = {};
    for (let i=0; i<n.length; i++)
    {
        result[n[i]] = (q1[i]+q2[i]+q3[i])/3;
    }
    return result;
}

function main() {
  const names = ["Ian", "Adrian", "Daniel", "Malcolm", "Roberson", "William", "Yousif", "Nicholas"];
  const quiz1 = [100, 100, 100, 100, 100, 100, 100, 100];
  const quiz2 = [90, 90, 90, 90, 90, 90, 90, 100];
  const quiz3 = [90, 80, 70, 60, 50, 40, 30, 100];
  const students = average(names, quiz1, quiz2, quiz3);
  console.log(students);
}

main();

/*
QUESTIONS:

Explain why each of the errors happened and how you fixed it.
- First Error: Average was computed incorrectly.
--- Caused all averages to be computed incorrectly.
--- Fixed by wrapping q1, q2, and q3 in parenthesis and then dividing by 3.
- Second Error: For loop initialized i to 1 instead of 0.
--- Caused Ian's quiz average to not be considered/computed.
--- Fixed by initializing i to 0.
- Third Error: quiz2 and quiz3 arrays missing an element each.
--- Caused Nicholas' average to be computed to NaN.
--- Fixed by adding 100 to the end of quiz2 and quiz3.

Which of the errors you found corresponds to an implicit conversion (coercion)
 error?
 - The third error found, where the quiz2 and quiz3 arrays were each missing an
   element, causing the function to access an out-of-bounds index of each array.
   Accessing those indices gives a value of undefined, thus resulting in
   Nicholas' average being NaN.
*/
