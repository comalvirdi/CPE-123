void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void doorClose(){

  enum {START, CLOSE_DOOR, CHECK_DOOR, OBJECT, NO_OBJECT};
  int state = START;

  switch(state){

    case START:

      state = CLOSE_DOOR;

    break;

    case CLOSE_DOOR:

      closed();
      state = CHECK_DOOR;

    break;
    
  }
  
}
