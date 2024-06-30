import time

class Motor:
    def __init__(self, name):
        self.name = name
        self.duty_cycle = 0
        self.state = 'stopped'

    def change_duty_cycle(self, duty_cycle):
        self.duty_cycle = duty_cycle
        print(f"{self.name} duty cycle changed to {duty_cycle}%")

    def forward(self):
        self.state = 'forward'
        print(f"{self.name} moving forward")

    def reverse(self):
        self.state = 'reverse'
        print(f"{self.name} moving backward")

    def stop(self):
        self.state = 'stopped'
        print(f"{self.name} stopped")

def test_motor():
    Motor1 = Motor('Motor1')
    Motor2 = Motor('Motor2')
    
    while True:
        # Forward motion
        for x in range(40, 45):
            print("FORWARD MOTION")
            Motor1.change_duty_cycle(x)
            Motor2.change_duty_cycle(x)
            Motor1.forward()
            Motor2.forward()
            time.sleep(0.1)

        print("STOP")
        Motor1.stop()
        Motor2.stop()
        time.sleep(5)

        # Backward motion
        for x in range(40, 45):
            print("BACKWARD MOTION")
            Motor1.change_duty_cycle(x)
            Motor2.change_duty_cycle(x)
            Motor1.reverse()
            Motor2.reverse()
            time.sleep(0.1)

        print("STOP")
        Motor1.stop()
        Motor2.stop()
        time.sleep(5)

# Run the test
test_motor()
