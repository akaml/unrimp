/*********************************************************\
 * Copyright (c) 2012-2018 The Unrimp Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


//[-------------------------------------------------------]
//[ Header guard                                          ]
//[-------------------------------------------------------]
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "RendererRuntime/Public/Resource/ResourceManager.h"

#include <Renderer/Public/Renderer.h>


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
namespace RendererRuntime
{
	class MeshResource;
	class IRendererRuntime;
	class IMeshResourceLoader;
	template <class TYPE, class LOADER_TYPE, typename ID_TYPE, uint32_t MAXIMUM_NUMBER_OF_ELEMENTS> class ResourceManagerTemplate;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace RendererRuntime
{


	//[-------------------------------------------------------]
	//[ Global definitions                                    ]
	//[-------------------------------------------------------]
	typedef uint32_t MeshResourceId;	///< POD mesh resource identifier


	//[-------------------------------------------------------]
	//[ Classes                                               ]
	//[-------------------------------------------------------]
	class MeshResourceManager final : public ResourceManager<MeshResource>
	{


	//[-------------------------------------------------------]
	//[ Friends                                               ]
	//[-------------------------------------------------------]
		friend class RendererRuntimeImpl;


	//[-------------------------------------------------------]
	//[ Public definitions                                    ]
	//[-------------------------------------------------------]
	public:
		RENDERERRUNTIME_API_EXPORT static const Renderer::VertexAttributes DRAW_ID_VERTEX_ATTRIBUTES;


	//[-------------------------------------------------------]
	//[ Public methods                                        ]
	//[-------------------------------------------------------]
	public:
		[[nodiscard]] RENDERERRUNTIME_API_EXPORT MeshResource* getMeshResourceByAssetId(AssetId assetId) const;	// Considered to be inefficient, avoid method whenever possible
		RENDERERRUNTIME_API_EXPORT void loadMeshResourceByAssetId(AssetId assetId, MeshResourceId& meshResourceId, IResourceListener* resourceListener = nullptr, bool reload = false, ResourceLoaderTypeId resourceLoaderTypeId = getInvalid<ResourceLoaderTypeId>());	// Asynchronous
		[[nodiscard]] RENDERERRUNTIME_API_EXPORT MeshResourceId createEmptyMeshResourceByAssetId(AssetId assetId);	// Mesh resource is not allowed to exist, yet, prefer asynchronous mesh resource loading over this method

		[[nodiscard]] inline const Renderer::IVertexBufferPtr& getDrawIdVertexBufferPtr() const
		{
			return mDrawIdVertexBufferPtr;
		}

		[[nodiscard]] inline const Renderer::IVertexArrayPtr& getDrawIdVertexArrayPtr() const
		{
			return mDrawIdVertexArrayPtr;
		}


	//[-------------------------------------------------------]
	//[ Public virtual RendererRuntime::IResourceManager methods ]
	//[-------------------------------------------------------]
	public:
		[[nodiscard]] virtual uint32_t getNumberOfResources() const override;
		[[nodiscard]] virtual IResource& getResourceByIndex(uint32_t index) const override;
		[[nodiscard]] RENDERERRUNTIME_API_EXPORT virtual IResource& getResourceByResourceId(ResourceId resourceId) const override;
		[[nodiscard]] virtual IResource* tryGetResourceByResourceId(ResourceId resourceId) const override;
		virtual void reloadResourceByAssetId(AssetId assetId) override;
		virtual void update() override;


	//[-------------------------------------------------------]
	//[ Private virtual RendererRuntime::IResourceManager methods ]
	//[-------------------------------------------------------]
	private:
		[[nodiscard]] virtual IResourceLoader* createResourceLoaderInstance(ResourceLoaderTypeId resourceLoaderTypeId) override;


	//[-------------------------------------------------------]
	//[ Private methods                                       ]
	//[-------------------------------------------------------]
	private:
		explicit MeshResourceManager(IRendererRuntime& rendererRuntime);
		virtual ~MeshResourceManager() override;
		explicit MeshResourceManager(const MeshResourceManager&) = delete;
		MeshResourceManager& operator=(const MeshResourceManager&) = delete;


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		ResourceManagerTemplate<MeshResource, IMeshResourceLoader, MeshResourceId, 4096>* mInternalResourceManager;
		Renderer::IVertexBufferPtr mDrawIdVertexBufferPtr;	///< Draw ID vertex buffer, see "17/11/2012 Surviving without gl_DrawID" - https://www.g-truc.net/post-0518.html
		Renderer::IVertexArrayPtr  mDrawIdVertexArrayPtr;	///< Draw ID vertex array, see "17/11/2012 Surviving without gl_DrawID" - https://www.g-truc.net/post-0518.html


	};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // RendererRuntime
