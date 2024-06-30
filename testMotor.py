import RPi.GPIO as GPIO
from time import sleep

# Pin Definitions
Motor1 = {'EN': 25, 'input1': 24, 'input2': 23}
Motor2 = {'EN': 17, 'input1': 27, 'input2': 22}

# Setup
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

for pin in Motor1.values():
    GPIO.setup(pin, GPIO.OUT)

for pin in Motor2.values():
    GPIO.setup(pin, GPIO.OUT)

EN1 = GPIO.PWM(Motor1['EN'], 100)  # channel=25 frequency=100Hz
EN2 = GPIO.PWM(Motor2['EN'], 100)  # channel=17 frequency=100Hz

EN1.start(0)
EN2.start(0)

try:
    while True:
        # Forward motion
        for x in range(40, 45):
            print("FORWARD MOTION")
            EN1.ChangeDutyCycle(x)
            EN2.ChangeDutyCycle(x)
            GPIO.output(Motor1['input1'], GPIO.HIGH)
            GPIO.output(Motor1['input2'], GPIO.LOW)
            GPIO.output(Motor2['input1'], GPIO.HIGH)
            GPIO.output(Motor2['input2'], GPIO.LOW)
            sleep(0.1)

        print("STOP")
        EN1.ChangeDutyCycle(0)
        EN2.ChangeDutyCycle(0)
        sleep(5)

        # Backward motion
        for x in range(40, 45):
            print("BACKWARD MOTION")
            EN1.ChangeDutyCycle(x)
            EN2.ChangeDutyCycle(x)
            GPIO.output(Motor1['input1'], GPIO.LOW)
            GPIO.output(Motor1['input2'], GPIO.HIGH)
            GPIO.output(Motor2['input1'], GPIO.LOW)
            GPIO.output(Motor2['input2'], GPIO.HIGH)
            sleep(0.1)

        print("STOP")
        EN1.ChangeDutyCycle(0)
        EN2.ChangeDutyCycle(0)
        sleep(5)

except KeyboardInterrupt:
    pass

finally:
    EN1.stop()
    EN2.stop()
    GPIO.cleanup()
