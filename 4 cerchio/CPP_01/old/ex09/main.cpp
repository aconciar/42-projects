/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrea <andrea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:25:50 by andrea            #+#    #+#             */
/*   Updated: 2024/09/07 14:47:39 by andrea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main() {
    // Creazione di un oggetto Logger con il file di log "logfile.txt"
    Logger logger("logfile.txt");

    // Loggare sulla console
    logger.log("console", "This is a message for the console.");

    // Loggare su un file
    logger.log("file", "This is a message for the file.");

    // Prova con una destinazione non valida
    logger.log("invalid", "This should give an error.");

    return (0);
}