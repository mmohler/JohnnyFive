#include <PinMap.h>
#include <Dagu4Motor.h>
#include <Drivetrain.h>

Dagu4Motor FLMotor = Dagu4Motor(Pin::mtr_spd_FL, Pin::mtr_dir_FL);
Dagu4Motor FRMotor = Dagu4Motor(Pin::mtr_spd_FR, Pin::mtr_dir_FR);
Dagu4Motor BLMotor = Dagu4Motor(Pin::mtr_spd_BL, Pin::mtr_dir_BL);
Dagu4Motor BRMotor = Dagu4Motor(Pin::mtr_spd_BR, Pin::mtr_dir_BR);
Drivetrain drive = Drivetrain(FLMotor, FRMotor, BLMotor, BRMotor);

void setup() {}
void loop() {
  drive.goFwd(100);
  delay(5000);
  drive.goBkwd(100);
  delay(5000);
  drive.turnL(100);
  delay(5000);
  drive.turnR(100);
  delay(5000);
  drive.stopMotors();
  delay(5000);
}
