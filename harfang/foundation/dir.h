// HARFANG(R) Copyright (C) 2021 Emmanuel Julien, NWNC HARFANG. Released under GPL/LGPL/Commercial Licence, see licence.txt for details.

#pragma once

#include "foundation/time.h"

#include <string>
#include <vector>

namespace hg {

enum DirEntryType { DE_File = 0x1, DE_Dir = 0x2, DE_Link = 0x4, DE_All = 0xffff };

struct DirEntry {
	int type{};
	std::string name;
	time_ns last_modified;
};

std::vector<DirEntry> ListDir(const char *path, int mask = DE_All);
std::vector<DirEntry> ListDirRecursive(const char *path, int mask = DE_All);

bool MkDir(const char *path, int permissions = 01777);
bool RmDir(const char *path);

bool MkTree(const char *path, int permissions = 01777);
bool RmTree(const char *path);

/// tmplt should end with at least six trailing 'x' characters
char *MkTempDir(const char *tmplt);

bool IsDir(const char *path);

bool CopyDir(const char *src, const char *dst);
bool CopyDirRecursive(const char *src, const char *dst);

bool Exists(const char *path);

} // namespace hg
