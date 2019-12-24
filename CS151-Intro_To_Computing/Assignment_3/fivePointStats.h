/*
//Name: Elvis Rodriguez
//Creation: 10/11/2017
//Version: 3.R
//Description: Prompts the user for five (5) inputs of type float and returns
               the maximum, minimum, median, first quartile, and third
               quartile of those five (5) numbers.
*/
#ifndef FIVEPOINTSTATS_H
#define FIVEPOINTSTATS_H

/*
//Name: swap()
//Parameter(s): float& a, float& b
//Return: none
//Label        Task               Goto
//01           (start: a, b)      02
//02           [float temp]       03
//03           [a --> temp]       04
//04           [b --> a]          05
//05           [temp --> b]       06
//06           (exit)
*/
void swap(float& a, float& b) {
  float temp;
  temp = a;
  a = b;
  b = temp;
}

/*
//Name: maximum()
//Parameter(s): float x, float y, float z, float w, float v
//Return: float
//Label    Task                                                          Goto
//01       (start: x, y, z, w, v)                                        02
//02       [float firstWinner, secondWinner, thirdWinner, finalWinner]   03
//03       < x > y >                                                     04,05
//04       [x --> firstWinner]                                           06
//05       [y --> firstWinner]                                           06
//06       < z > w >                                                     07,08
//07       [z --> secondWinner]                                          09
//08       [w --> secondWinner]                                          09
//09       < firstWinner > secondWinner >                                10,11
//10       [firstWinner --> thirdWinner]                                 12
//11       [secondWinner --> thirdWinner]                                12
//12       < thirdWinner > v >                                           13, 14
//13       [thirdWinner --> finalWinner]                                 15
//14       [v --> finalWinner]                                           15
//15       (exit: finalWinner)
*/
float maximum(float x, float y, float z, float w, float v) {
  float firstWinner, secondWinner, thirdWinner, finalWinner;
  if (x > y) {
    firstWinner = x;
  } else {
    firstWinner = y;
  }

  if (z > w) {
    secondWinner = z;
  } else {
    secondWinner = w;
  }

  if (firstWinner > secondWinner) {
    thirdWinner = firstWinner;
  } else {
    thirdWinner = secondWinner;
  }

  if (thirdWinner > v) {
    finalWinner = thirdWinner;
  } else {
    finalWinner = v;
  }

  return finalWinner;
}

/*
//Name: minimum()
//Parameter(s): float x, float y, float z, float w, float v
//Return: float
//Label    Task                                                          Goto
//01       (start: x, y, z, w, v)                                        02
//02       [float firstWinner, secondWinner, thirdWinner, finalWinner]   03
//03       < x < y >                                                     04,05
//04       [x --> firstWinner]                                           06
//05       [y --> firstWinner]                                           06
//06       < z < w >                                                     07,08
//07       [z --> secondWinner]                                          09
//08       [w --> secondWinner]                                          09
//09       < firstWinner < secondWinner >                                10,11
//10       [firstWinner --> thirdWinner]                                 12
//11       [secondWinner --> thirdWinner]                                12
//12       < thirdWinner < v >                                           13, 14
//13       [thirdWinner --> finalWinner]                                 15
//14       [v --> finalWinner]                                           15
//15       (exit: finalWinner)
*/
float minimum(float x, float y, float z, float w, float v) {
  float firstWinner, secondWinner, thirdWinner, finalWinner;
  if (x < y) {
    firstWinner = x;
  } else {
    firstWinner = y;
  }

  if (z < w) {
    secondWinner = z;
  } else {
    secondWinner = w;
  }

  if (firstWinner < secondWinner) {
    thirdWinner = firstWinner;
  } else {
    thirdWinner = secondWinner;
  }

  if (thirdWinner < v) {
    finalWinner = thirdWinner;
  } else {
    finalWinner = v;
  }

  return finalWinner;
}

/*
//Name: median()
//Parameter(s): float x, float y, float z, float w, float v
//Return: float
//Label         Task                                      Goto
//01            (start: x, y, z, w, v)                    02
//02            < x > y >                                 03,04
//03            [swap(x,y)]                               04
//04            < x > z >                                 05,06
//05            [swap(x,z)]                               06
//06            < x > w >                                 07,08
//07            [swap(x,w)]                               08
//08            < x > v >                                 09,10
//09            [swap(x,v)]                               10
//10            < y > z >                                 11,12
//11            [swap(y,z)]                               12
//12            < y > w >                                 13,14
//13            [swap(y,w)]                               14
//14            < y > v >                                 15,16
//15            [swap(y,v)]                               16
//16            < z > w >                                 17, 18
//17            [swap(z,w)]                               18
//18            < z > v >                                 19,20
//19            [swap(z,v)]                               20
//20            < w > v >                                 21,22
//21            [swap(w,v)]                               22
//22            (exit: z)
*/
float median(float x, float y, float z, float w, float v) {
  if (x > y) {swap(x, y);}

  if (x > z) {swap(x, z);}

	if (x > w) {swap(x, w);}

	if (x > v) {swap(x, v);}

  if (y > z) {swap(y, z);}

	if (y > w) {swap(y, w);}

	if (y > v) {swap(y, v);}

  if (z > w) {swap(z, w);}

	if (z > v) {swap(z, v);}

  if (w > v) {swap(w, v);}

  return z;
}

/*
//Name: firstQuartile()
//Parameter(s): float x, float y, float z, float w, float v
//Return: float
//Label         Task                                      Goto
//01            (start: x, y, z, w, v)                    02
//02            < x > y >                                 03,04
//03            [swap(x,y)]                               04
//04            < x > z >                                 05,06
//05            [swap(x,z)]                               06
//06            < x > w >                                 07,08
//07            [swap(x,w)]                               08
//08            < x > v >                                 09,10
//09            [swap(x,v)]                               10
//10            < y > z >                                 11,12
//11            [swap(y,z)]                               12
//12            < y > w >                                 13,14
//13            [swap(y,w)]                               14
//14            < y > v >                                 15,16
//15            [swap(y,v)]                               16
//16            < z > w >                                 17, 18
//17            [swap(z,w)]                               18
//18            < z > v >                                 19,20
//19            [swap(z,v)]                               20
//20            < w > v >                                 21,22
//21            [swap(w,v)]                               22
//22            (exit: y)
*/
float firstQuartile(float x, float y, float z, float w, float v) {
  if (x > y) {swap(x, y);}

  if (x > z) {swap(x, z);}

  if (x > w) {swap(x, w);}

  if (x > v) {swap(x, v);}

  if (y > z) {swap(y, z);}

  if (y > w) {swap(y, w);}

  if (y > v) {swap(y, v);}

  if (z > w) {swap(z, w);}

  if (z > v) {swap(z, v);}

  if (w > v) {swap(w, v);}

  return y;
}

/*
//Name: thirdQuartile()
//Parameter(s): float x, float y, float z, float w, float v
//Return: float
//Label         Task                                      Goto
//01            (start: x, y, z, w, v)                    02
//02            < x > y >                                 03,04
//03            [swap(x,y)]                               04
//04            < x > z >                                 05,06
//05            [swap(x,z)]                               06
//06            < x > w >                                 07,08
//07            [swap(x,w)]                               08
//08            < x > v >                                 09,10
//09            [swap(x,v)]                               10
//10            < y > z >                                 11,12
//11            [swap(y,z)]                               12
//12            < y > w >                                 13,14
//13            [swap(y,w)]                               14
//14            < y > v >                                 15,16
//15            [swap(y,v)]                               16
//16            < z > w >                                 17, 18
//17            [swap(z,w)]                               18
//18            < z > v >                                 19,20
//19            [swap(z,v)]                               20
//20            < w > v >                                 21,22
//21            [swap(w,v)]                               22
//22            (exit: w)
*/
float thirdQuartile(float x, float y, float z, float w, float v) {
  if (x > y) {swap(x, y);}

  if (x > z) {swap(x, z);}

  if (x > w) {swap(x, w);}

  if (x > v) {swap(x, v);}

  if (y > z) {swap(y, z);}

  if (y > w) {swap(y, w);}

  if (y > v) {swap(y, v);}

  if (z > w) {swap(z, w);}

  if (z > v) {swap(z, v);}

  if (w > v) {swap(w, v);}

  return w;
}

#endif //FIVEPOINTSTATS_H
