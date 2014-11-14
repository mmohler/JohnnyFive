PathMaker::PathMaker() {
  compass = 0;
  mazeSize = 5; //Need to ultimately read the output of the switch on the robot and figure out what is going on from there.
  switch(mazeSize) {
    case 5:
      start = 1;
      end = 1;
      break;
    case 6:
      start = 1;
      end = 1;
      break;
    case 7:
      start = 1;
      end = 1;
      break;
  }
}

PathMaker::straight() {
  //call to motor function drive straight
  compass = compass;
  switch(compass) {
    case 0:
      criticalPath[curIdx++] = criticalPath[curIdx]+7;
    case 1:
      criticalPath[curIdx++] = criticalPath[curIdx]+1;
    case 2:
      criticalPath[curIdx++] = criticalPath[curIdx]-7;
    case 3:
      criticalPath[curIdx++] = criticalPath[curIdx]-1;
  }
}
