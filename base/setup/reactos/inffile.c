/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS text-mode setup
 * FILE:            base/setup/usetup/inffile.c
 * PURPOSE:         .inf files support functions
 * PROGRAMMERS:     Herv� Poussineau
 *                  Hermes Belusca-Maito (hermes.belusca@sfr.fr)
 */

/* INCLUDES ******************************************************************/

#include "reactos.h"

#define NDEBUG
#include <debug.h>

/* SETUP* API COMPATIBILITY FUNCTIONS ****************************************/

/* Functions from the INFLIB library */

/* SetupOpenInfFileW with support for a user-provided LCID */
HINF
WINAPI
SetupOpenInfFileExW(
    IN PCWSTR FileName,
    IN PCWSTR InfClass,
    IN DWORD InfStyle,
    IN LCID LocaleId,
    OUT PUINT ErrorLine)
{
    UNREFERENCED_PARAMETER(LocaleId);
    return SetupOpenInfFileW(FileName, InfClass, InfStyle, ErrorLine);
}


/* HELPER FUNCTIONS **********************************************************/

#if 0

HINF WINAPI
INF_OpenBufferedFileA(
    IN PSTR FileBuffer,
    IN ULONG FileSize,
    IN PCSTR InfClass,
    IN DWORD InfStyle,
    IN LCID LocaleId,
    OUT PUINT ErrorLine)
{
#ifdef __REACTOS__
    HINF hInf = NULL;
    ULONG ErrorLineUL;
    NTSTATUS Status;

    Status = InfOpenBufferedFile(&hInf,
                                 FileBuffer,
                                 FileSize,
                                 LANGIDFROMLCID(LocaleId),
                                 &ErrorLineUL);
    *ErrorLine = (UINT)ErrorLineUL;
    if (!NT_SUCCESS(Status))
        return INVALID_HANDLE_VALUE;

    return hInf;
#else
    return INVALID_HANDLE_VALUE;
#endif /* !__REACTOS__ */
}

#endif

/* EOF */
