#include <stdio.h>
// Zwischentest 1: Grade calculator

// updates achievable_points, total_points, type_points if note input passed the check
void update_points(char type, double curr_points, double max_points, double* type_points, double* achievable_points, double* total_points) {

    (*total_points) += curr_points;
    (*type_points) += curr_points;

    if (type == 'u') {
        // total points for u cannot be bigger than 10
        if ((*type_points) > 10) (*type_points) = 10;
    }
    // max_points are added to achievable_points for all types other than 'u'
    else (*achievable_points) += max_points;
}

// returns 1 (true) if curr_points is in the allowed range, else prints error message and returns 0 (false)
int check_min_max(double curr_points, double min, double max) {

    if ((curr_points >= min) & (curr_points <= max)) return 1;
    else {
        printf("\nungueltiger Bereich: min %.2lf, max %.2lf", min, max);
        return 0;
    }
}

// checks if points input is valid and if so, updates current points, achievable points and total points
void check_and_update_points(char type, double* type_points, double min, double max, double curr_points, double* achievable_points, double* total_points) {

    if (check_min_max(curr_points, min, max)) {
        update_points(type, curr_points, max, type_points, achievable_points, total_points);
    }
}

// prints current at_points, zt_points, ue_points and achievable_points
void print_current_points(double at_points, double zt_points, double ue_points, double achievable_points) {

    printf("\nZT Punkte: %.2lf", zt_points);
    printf("\nAT Punkte: %.2lf", at_points);
    printf("\nUE Punkte: %.2lf", ue_points);
    printf("\nErreichbare Gesamtpunkte: %.2lf", achievable_points);
}

// calculates final grade [1, 5]
int get_grade(double at_points, double zt_points, double ue_points, double* total_points, double achievable_points) {

    // first sum at_points and zt_points; if it's less than 55% from the achievable points, final grade is 5
    double at_plus_zt = at_points + zt_points;

    if (at_plus_zt/achievable_points < 0.55) {
        (*total_points) = at_plus_zt;
        return 5;
    }

    // sum ue_points and calculate final grade [1, 4]
    else {
        double total = at_plus_zt + ue_points;
        double total_relative = total/achievable_points;

        if (total_relative < 0.67) return 4;
        else if (total_relative < 0.78) return 3;
        else if (total_relative < 0.89) return 2;
        else return 1;
    }
}

// prints the Gesamtpunkte absolut, Gesamtpukte and Note
void print_final_grade(double at_points, double zt_points, double ue_points, double achievable_points, double* total_points) {
    if (achievable_points == 0) {
        printf("\nGesamtpunkte absolut: 0.00");
        printf("\nGesamtpunkte %%: 0.00 %%");
        printf("\nNote: 0");
    }
    else {
        int final_grade = get_grade(at_points, zt_points, ue_points, total_points, achievable_points);
        double points_percent = 100*((*total_points)/achievable_points);
        printf("\nGesamtpunkte absolut: %.2lf", (*total_points));
        printf("\nGesamtpunkte %%: %.2lf %%", points_percent);
        printf("\nNote: %d", final_grade);
    }
}



int main() {

    // initialize point count
    double at_points = 0 , zt_points = 0, ue_points = 0, achievable_points = 0, total_points = 0;
    double min_a = 0, min_z = 0, min_u = 0;
    double max_a = 70;
    double max_z = 10;
    double max_u = 0.5;

    // print initial state before getting inputs
    print_current_points(at_points, zt_points, ue_points, achievable_points);

    // loop for reading inputs
    while (1) {

        // get inputs
        char curr_type;
        double curr_points;

        // get type input
        printf("\nTyp:");
        scanf("\n%c", &curr_type);

        // if user types '=', print final grade and break loop
        if (curr_type == '=') {
            print_final_grade(at_points, zt_points, ue_points, achievable_points, &total_points);
            break;
        }

        // if an Abschlusstest was already counted, print error, print current points and continue next loop iteration
        if ((curr_type == 'a') & (at_points > 0)) {
            printf("\nnur ein Abschlusstest erlaubt");
            print_current_points(at_points, zt_points, ue_points, achievable_points);
            continue;
        }

        // get points input
        printf("\nPunkte:");
        scanf("\n%lf", &curr_points);

        // check user input and if it's valid, update achievable points and total points. Otherwise, ignore input
        switch(curr_type) {
            case 'z':
               check_and_update_points(curr_type, &zt_points, min_z, max_z, curr_points, &achievable_points, &total_points);
               break;
            case 'a':
                check_and_update_points(curr_type, &at_points, min_a, max_a, curr_points, &achievable_points, &total_points);
                break;
            case 'u':
                check_and_update_points(curr_type, &ue_points, min_u, max_u, curr_points, &achievable_points, &total_points);
                break;
            default:
                break;
        }

        // output current results
        print_current_points(at_points, zt_points, ue_points, achievable_points);
    }

    return 0;
}
