//
// Created by Besnik Nuro on 18/05/23.
//

#ifndef NAMEPLACEHOLDER_DEFINITIONS_H
#define NAMEPLACEHOLDER_DEFINITIONS_H

enum OS {
    NT,
    Linux,
    MacOS
};

#ifdef _WIN32
const OS os = NT;
#elif __linux__
const OS os = Linux;
#elif __APPLE__
const OS os = MacOS;
#endif

#define INVERTEDCOLORING 1

#endif //NAMEPLACEHOLDER_DEFINITIONS_H
