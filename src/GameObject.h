
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:

  enum class State { nonVisible, idle, moveToRight, moveToLeft, fire};

  GameObject(){};
  ~GameObject(){};

  int GetPos_x() const; 
  int GetPos_y() const;

  void SetPos_x(int pos_x);
  void SetPos_y(int pos_y);

  void SetState(GameObject::State state); 
  
  State state {State::idle};

  /*virtual*/ void Update ();

protected:
  int _pos_x{0};
  int _pos_y{0};

private:

};


#endif