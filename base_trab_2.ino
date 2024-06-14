//TÉCNICO EM DESENVOLVIMENTO DE SISTEMAS - SENAC NH
//Programa base para TRABALHO 2
//PROF.: Glauber Kiss de Souza
//DISC.: Analizar Orient. Técnicas
//This programm it´s about microcontroller made in Arduino system, the original creator is Glauber Kiss de Souza, who shared the file.
int soma = 13; // Input pin for the 'soma' signal
int carryBit = 0; // Variable to store the carry bit
int nib1a, nib1b, nib1c, nib1d = 0; // Variables for the first 4-bit number
int nib2a, nib2b, nib2c, nib2d = 0; // Variables for the second 4-bit number
int res1a, res1b, res1c, res1d = 0; // Variables to store the result bits

void setup() {
    // Set input pins for the 4-bit numbers and soma signal
    pinMode(0, INPUT);
    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT); // Output pin for the result bit 0
    pinMode(9, OUTPUT); // Output pin for the result bit 1
    pinMode(10, OUTPUT); // Output pin for the result bit 2
    pinMode(11, OUTPUT); // Output pin for the result bit 3
    pinMode(12, OUTPUT); // Output pin for the carry bit
    pinMode(13, INPUT); // Input pin for the soma signal
}

int somaBit(int b1a, int b2a, int cBit) {
    // Calculate the sum bit (S) of two bits (b1a, b2a) with the carry-in (cBit)
    return (b1a ^ b2a) ^ cBit; // XOR operation for sum
}

int somaCarryBit(int b1a, int b2a, int cBit) {
    // Calculate the carry-out (Cout) of two bits (b1a, b2a) with the carry-in (cBit)
    return (b1a & b2a) | (b1a & cBit) | (b2a & cBit); // AND and OR operations for carry
}

void loop() {
    // Read the value of the soma signal
    soma = digitalRead(13);

    // Read the bits of the first 4-bit number
    nib1a = digitalRead(0);
    nib1b = digitalRead(1);
    nib1c = digitalRead(2);
    nib1d = digitalRead(3);

    // Read the bits of the second 4-bit number
    nib2a = digitalRead(4);
    nib2b = digitalRead(5);
    nib2c = digitalRead(6);
    nib2d = digitalRead(7);

    if (soma == 1) { // If soma signal is active
        carryBit = 0; // Initialize carry bit to 0

        // Perform bitwise addition for each bit and update the carry bit
        res1a = somaBit(nib1a, nib2a, carryBit);
        carryBit = somaCarryBit(nib1a, nib2a, carryBit);
        res1b = somaBit(nib1b, nib2b, carryBit);
        carryBit = somaCarryBit(nib1b, nib2b, carryBit);
        res1c = somaBit(nib1c, nib2c, carryBit);
        carryBit = somaCarryBit(nib1c, nib2c, carryBit);
        res1d = somaBit(nib1d, nib2d, carryBit);
        carryBit = somaCarryBit(nib1d, nib2d, carryBit);
    }

    // Output the result bits to the respective pins
    digitalWrite(8, res1a);
    digitalWrite(9, res1b);
    digitalWrite(10, res1c);
    digitalWrite(11, res1d); 
    // Output the final carry bit
    digitalWrite(12, carryBit);
}
