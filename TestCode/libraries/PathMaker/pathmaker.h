class PathMaker {
  int compass; //0=N, 1=E, 2=S, 3=W
  int mazeSize;
  int start, finish;
  int curIdx;
  byte criticalPath[51];

  public:
    void PathMaker(void);
    void straight(void);
    void left(void);
    void right(void);
  
  private:
    void update(int);
    void generatePath();
}
