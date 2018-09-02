# Assignment 1 - Fours' Company

## DOCKER PREPARATION
* Create an Ubuntu Docker image by following this tutorial:

    https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-16-04

* In the host computer terminal, get the container running by executing the following command and keep this terminal open.

    ```
    docker run -it ubuntu /bin/bash
    ```
    
* Now to get the containerID (or name) of the docker, execute this on a new terminal on the host:

     ```
    docker ps
    ```
    
* The IP address can now be obtained by running this on the host

     ```
    docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' container_name_or_id
    ```
    
* Keep this IP address handy, as it will be used later. Do not close this container, if you do then go back to the second step and get the new IP.   
    
    
## SET UP THE CLIENT-SERVER BINARIES:

* Clone this repository

    ```
    git clone https://github.com/NamanJain8/assignment-1-fours-company.git
    ```

* Navigate to the directory.

    ```
    cd assignment-1-fours-company
    ```
    
* In `server.c` and `client.c`, replace "172.17.0.3" with the IP address obtained above
    
    ```diff
    - serverAddr.sin_addr.s_addr = inet_addr("172.17.0.3");
    + serverAddr.sin_addr.s_addr = inet_addr("IP_address_obtained_above");
    ```
    
* Compile the server and client code.
    
    ```
    gcc server.c -o server
    gcc client.c -o client
    ```
    
* Copy the `client` binary into any directory where you wish to receive data.

* Move the `server` binary and `files` directory into the running docker container (in the same directory) by executing this in the host shell
    
    ```
    docker cp server containerID:/server
    docker cp files/. containerID:/files
    ```
    
* On the interactive docker terminal, execute the `server` binary.
    
    ```
    ./server
    ```
    
    The server is now up and running.

* On the client side directory, now execute the `client` binary. The file expects input of the form "2 cars, 3 dogs and 4 trucks" etc. The supported classes are dogs, cats, cars and trucks. The supported range of numbers is 1-4.

    ```    
    ./client
    2 cars, 3 dogs and 4 trucks
    ```

## THE FLOW OF CONTROL

* The `client` binary sends in the request to the server running in the docker.

* An `index.html` file is created on the server, on demand, as per the request.

* Once prepared, `index.html` and the required images are sent over to the client and are stored in the current client directory.

* A browser can now be used to render output (open the file `index.html` in a browser of your chice).
