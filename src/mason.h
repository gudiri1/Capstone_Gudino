#ifndef MASON_H
#define MASON_H

class Mason
{
public:

  Mason() {
    body1_x = 0;
    body1_y = 550;

    //body2_x = 100;
    //body2_y = 600;
  }    

void Update(bool &DirFlag);

float body1_x;
float body1_y;

float body2_x;
float body2_y;

private:


};

#endif