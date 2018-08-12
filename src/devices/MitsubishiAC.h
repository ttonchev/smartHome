#include <Settings.h>
#include <ir_Mitsubishi.h>
class MitsubishiAC {
public:

  MitsubishiAC();
  void on();
  void off();
  void mode(String mode);
  void vaneMode(String mode);
  void setTemp(int temp);
  void setFan(int power);
private:

  IRMitsubishiAC mitsubir;

};
