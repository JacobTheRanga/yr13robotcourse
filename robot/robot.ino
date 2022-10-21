int ls[4] = {0, 1, 2, 3}; // Line Sensors
int m[4] = {13, 12, 9, 8}; // Motors
int ms[2] = {11, 5}; // Motor speed
int lsval[4]; // Line Sensor Values
int sf = 9600; // Serial Frequency
int timer = 0; // Timer
int range[400]; // Range
int min[4]; // Minimum in range
int max[4]; // Maximum value in range
int err[4]; // Error

void setup(){
    for (int i = 0; i < 4; i++){
        pinMode(m[i], OUTPUT);
    }
    analogWrite(ms[0], 255);
    analogWrite(ms[1], 255);
    Serial.begin(sf);

        while (timer < 100){
        lsread();
        for (int i = 0; i < 4; i++){
            range[(timer*4)+i] = lsval[i];
        }
        timer++;
        delay(1);
    }
    for (int i = 0; i < 100; i++){
        for (int a = 0; a < 4; a++){
            if (i = 0) min[a] = range[(i*4)+a];
            if (i = 1){
                if (range[(i*4)+a] <= min[a]){
                    max[a] = min[a];
                    min[a] = range[(i*4)+a];
                }
                else{
                    max[a] = range[(i*4)+a];
                }
            }
            if (i > 1){
                if (range[(i*4)+a] <= min[a]){
                    min[a] = range[(i*4)+a];
                }
                else if (range[(i*4)+a] >= max[a]){
                    max[a] = range[(i*4)+a];
                }
            }
        }
    }
    for (int i = 0; i < 4; i++){
        Serial.print(min[i]);
        Serial.print(' ');
        Serial.println(max[i]);
    }
}

// Line sensor read
int lsread(){
    for (int i = 0; i < 4; i++){
        lsval[i] = analogRead(A+ls[i]);
    }
}

void loop(){

}