/**
 * @file CommandInterpreter.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Command interpreter class header.
 * 
 */

#ifndef KNAPSACK_COMMAND_INTERPRETER_H
#define KNAPSACK_COMMAND_INTERPRETER_H

#include <iostream>
#include <string>
#include "TestModule.h"

namespace Knapsack {

    /**
     * @brief Possible commands
     * 
     */
    enum class Commands { HELP, RUN, GENERATE, TEST };

    /**
     * @brief Command interpreter class only for static methods
     * 
     */
    class CommandInterpreter {
    private:

        /**
         * @brief Act accordingly to command
         * 
         * @tparam command 
         * @tparam algorithm 
         */
        template <Commands command, Algorithm algorithm> static void runCommand();

    public:

        CommandInterpreter() = delete;

        CommandInterpreter(const CommandInterpreter& other) = delete;

        CommandInterpreter(CommandInterpreter&& other) = delete;

        ~CommandInterpreter() = delete;

        CommandInterpreter operator=(const CommandInterpreter& other) = delete;

        CommandInterpreter operator=(CommandInterpreter&& other) = delete;

        /**
         * @brief Interprete execution argument as execution mode and act accordingly
         * 
         * @param command execution argument
         */
        static void interprete (std::string command, std::string algorithm);
    };
}

#endif