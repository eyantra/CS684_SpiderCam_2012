//Project: Spider Cam
//Group: 10

Steps to Follow
1.first check the clock frequency on your bot
2.in file Xbee.h change the F_CPU value as per the step 1(values are already written in code just select appropriate one)
3.configure Xbee modules(refer X-CTU manual)
4.compile the program and load exe file(shaftencoder1.hex in default folder) to FireBird 
5.now you can send commands to Xbee module on bot  
 (bot has 2 modes to operate..COMMAND mode & AUTOMATED mode)
6.
i]syntax to follow to use bot in COMMAND mode
  <botId>$1$<direction>#

  <botId> = 10
  <direction> can be f/b/u/d/r/l
  f-Forward
  b-Backward
  u-Up
  d-Down
  r-Right
  l-Left
ex. 
    10$1$u#
    10$1$f# 
ii]syntax to follow to use bot in AUTOMATED mode
  <botId>$2$<direction>$<distance_in_centimeter>$<number_of_troughs>#
ex.
    10$2$f$400$3#

