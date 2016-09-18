#ifndef LIKNORM_H
#define LIKNORM_H

typedef void log_partition (double  x,
                            double *A0,
                            double *logA1,
                            double *logA2);

typedef struct
{
    double Ty;
    log_partition* lp;
} ExpFam;

typedef struct
{
  double eta;
  double tau;
} Normal;

typedef struct
{
    double *log_zeroth;
    double *log_first;
    double *log_second;
    int n;
    double precision;
} LikNormMachine;

LikNormMachine* create_liknorm_machine(int n, double precision);
void destroy_liknorm_machine(LikNormMachine* machine);
void integrate(LikNormMachine *machine, ExpFam ef, Normal normal);

#endif /* ifndef LIKNORM_H */