#include <iostream>
#include <cmath>
using namespace std;

// Structure to store system data
struct system_data {
    double coefficients[10][10];
    double constants[10];
    double previous[10];
    double current[10];
    double relative_error[10];
};

// Display nx1 vector
void display_vector(double arr[], int n, const string& title) {
    cout << title << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << arr[i] << endl;
    }
    cout << endl;
}

// Compute relative error
void compute_error(double prev[], double curr[], double rel_err[], int n) {
    for (int i = 0; i < n; i++) {
        if (curr[i] != 0)
            rel_err[i] = fabs((curr[i] - prev[i]) / curr[i]);
        else
            rel_err[i] = 0;
    }
}

// Perform one Gauss-Seidel iteration
void gauss_seidel_step(double A[][10], double b[], double prev[], double curr[], int n) {
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                // Use the latest available value
                sum += (j < i ? curr[j] : prev[j]) * A[i][j];
            }
        }
        curr[i] = (b[i] - sum) / A[i][i];
    }
}

int main() {
    int n;
    cout << "Enter the size of the system (n x n): ";
    cin >> n;

    system_data sys;

    // Input matrix coefficients
    cout << "\nEnter the coefficients of the matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> sys.coefficients[i][j];
        }
    }

    // Input constants (b vector)
    cout << "\nEnter the constants (b vector):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "b[" << i + 1 << "]: ";
        cin >> sys.constants[i];
    }

    // Input initial guess
    cout << "\nEnter the initial guess vector:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << ": ";
        cin >> sys.previous[i];
    }

    char cont = 'y';
    int iteration = 1;

    while (cont == 'y' || cont == 'Y') {
        cout << "\n--- Iteration " << iteration << " ---" << endl;

        // Perform Gauss-Seidel step
        gauss_seidel_step(sys.coefficients, sys.constants, sys.previous, sys.current, n);

        // Compute relative errors
        compute_error(sys.previous, sys.current, sys.relative_error, n);

        // Display current solution
        display_vector(sys.current, n, "Current values:");

        // Display errors
        cout << "Relative errors:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Error x" << i + 1 << " = " << sys.relative_error[i] << endl;
        }
        cout << endl;

        // Copy current to previous for next iteration
        for (int i = 0; i < n; i++) {
            sys.previous[i] = sys.current[i];
        }

        // Ask user to continue
        cout << "Do you want to perform another iteration? (y/n): ";
        cin >> cont;
        iteration++;
    }

    cout << "\nProgram terminated by user." << endl;
    return 0;
}
