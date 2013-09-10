#include <QCoreApplication>
#include <iostream>
#include <errno.h>
#include "servidor.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <fstream>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /*Se cierran los descriptores para que no hayan salidas que no se quieren tener */
    // Cerrar los descriptores de la E/S estándar
    close(STDIN_FILENO);                    // fd 0
    close(STDOUT_FILENO);                   // fd 1
    close(STDERR_FILENO);                   // fd 2

    int fd0 = open("/dev/null", O_RDONLY);  // fd0 == 0
    int fd1 = open("/dev/null", O_WRONLY);  // fd0 == 1
    int fd2 = open("/dev/null", O_WRONLY);  // fd0 == 2

    pid_t pid;

    // Nos clonamos a nosotros mismos creando un proceso hijo
    pid = fork();

    // Si pid es < 0, fork() falló
    if (pid < 0) {
        // Mostrar la descripción del error y terminar
       std::cerr << strerror(errno) << std::endl;
        exit(10);
    }

    // Si pid es > 0, estamos en el proceso padre
    if (pid > 0) {
        // Terminar el proceso
        exit(0);
    }

    // Si la ejecución llega a este punto, estamos en el hijo

    pid_t sid;

    // Intentar crear una nueva sesión
    sid = setsid();
    if (sid < 0) {
        syslog(LOG_ERR, "No fue posible crear una nueva sesión\n");
        exit(11);
    }

    //Cambiamos el directorio de trbaajo del demonio.
    if ((chdir("/home/adri/Documentos/Tercer_Ano/SOA/1/videovigilancia-capturer-g02/capturaservidor/imagenes")) < 0) {
        syslog(LOG_ERR, "No fue posible cambiar el directorio de "
                        "trabajo a /\n");
        exit(12);
    }
    syslog(LOG_NOTICE, "no se creo el archivo\n");

    umask(0);


    QCoreApplication a(argc, argv);
    
    // Abrir una conexión al demonio syslog
    openlog(argv[0], LOG_NOWAIT | LOG_PID, LOG_USER);




    // Enviar un mensaje al demonio syslog
    syslog(LOG_NOTICE, "Demonio iniciado con éxito\n");




    //Creamos un archivo en /var/run con el pid del demonio

     std::ofstream fichero;
     fichero.open("/var/run/midemonio.pid");

     int pid2 = getpid();
     QString pid3("%1");


     syslog(LOG_NOTICE, pid3.arg(pid2).toLocal8Bit());

     fichero<<pid2;

     fichero.close();

    // Cambiar el usuario efectivo del proceso a 'midemonio'
    passwd* user = getpwnam("midemonio");

    if (user == NULL){
        syslog(LOG_NOTICE, "No existe el usuario ha sido creado\n");

    }
    else seteuid(user->pw_uid);

    // Cambiar el grupo efectivo del proceso a 'midemonio'

    group* grup = getgrnam("midemonio");

    if (grup == NULL){
        syslog(LOG_NOTICE, "No existe el Grupo ha sido creado\n");
    }
    else setegid(grup->gr_gid);



    int salida =10;
    while (salida == 10) {
        Servidor server;

        salida = a.exec();
    }

        // Cuando el demonio termine, cerrar la conexión con
    // el servicio syslog

    closelog();
}
