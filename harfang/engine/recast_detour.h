// HARFANG(R) Copyright (C) 2021 Emmanuel Julien, NWNC HARFANG. Released under GPL/LGPL/Commercial Licence, see licence.txt for details.

#pragma once

#include "foundation/rw_interface.h"
#include "foundation/vector3.h"

#include "engine/render_pipeline.h"

#include <bgfx/bgfx.h>

#include <vector>

class dtNavMesh;
class dtNavMeshQuery;

namespace hg {

struct RenderState;
struct Geometry;

//
static const int NAVMESHSET_MAGIC = 'M' << 24 | 'S' << 16 | 'E' << 8 | 'T'; //'MSET';
static const int NAVMESHSET_VERSION = 1;

//
dtNavMesh *LoadNavMesh(const char *path, const Reader &ir, const ReadProvider &ip);
dtNavMesh *LoadNavMeshFromFile(const char *path);
dtNavMesh *LoadNavMeshFromAssets(const char *path);

void DestroyNavMesh(dtNavMesh *mesh);

//
void DrawNavMesh(const dtNavMesh *mesh, bgfx::ViewId view_id, const bgfx::VertexLayout &vtx_layout, bgfx::ProgramHandle program,
	const std::vector<UniformSetValue> &values, const std::vector<UniformSetTexture> &textures, RenderState state);

//
struct NavMeshInput {
	std::vector<Vec3> vtx;
	std::vector<int> idx;
};

void AddGeometryToNavMeshInput(NavMeshInput &input, const Geometry &geo, const Mat4 &world);
dtNavMesh *CreateNavMesh(const NavMeshInput &input, float radius, float height, float slope, float climb);

//
dtNavMeshQuery *CreateNavMeshQuery(const dtNavMesh *mesh);
void DestroyNavMeshQuery(dtNavMeshQuery *query);

/// Perform a path query.
std::vector<Vec3> FindNavigationPathTo(const dtNavMeshQuery *query, const Vec3 &from, const Vec3 &to);

} // namespace hg
