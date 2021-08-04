/*-----------------------------------------------------------------------------*/
/*    Distributed by Wireless Innovation Forum                                 */
/*    Copyright 2021 SDS Project Authors. All Rights Reserved.				   */
/*    Licensed under the Apache License, Version 2.0 (the "License");		   */
/*    you may not use this file except in compliance with the License.		   */
/*    You may obtain a copy of the License at                                  */
/*                                                                             */
/*        http://www.apache.org/licenses/LICENSE-2.0						   */
/*																			   */
/*    Unless required by applicable law or agreed to in writing, software	   */
/*    distributed under the License is distributed on an "AS IS" BASIS,		   */
/*    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/*    See the License for the specific language governing permissions and      */
/*    limitations under the License.										   */
/*-----------------------------------------------------------------------------*/
/* Title : TsfPlatformProviderAdaptations.hpp					 		       */
/* Date:  2021-08-04														   */
/* Version:  1.0.0															   */
/* Purpose: The TsfPlatformProviderAdaptations.hpp file is specified as the    */
/*          header file specifying the ActiveServicesAccess property           */
/*          TsfPlatformProviderAdaptations.hpp has to be adapted by platform   */
/*          providers only in areas marked with *** PROVIDER-ADAPTATION ***.   */
/*-----------------------------------------------------------------------------*/

// Specifies PlatformProvider-adaptations:
//  ActiveServicesAccess property, specified by section 2.3 of [PSM]
#ifndef TSF_PLATFORM_PROVIDER_ADAPTATIONS
#define TSF_PLATFORM_PROVIDER_ADAPTATIONS
// ActiveServicesAccess
// *** PROVIDER-ADAPTATION ***
#define EXPLICIT_SERVICES_ACCESS // comment if EXPLICIT is not supported
#define GENERIC_SERVICES_ACCESS  // comment if GENERIC is not supported
#define EXCEPTIONS_SUPPORT	    // comment if EXCEPTIONS is not supported

#endif // #ifndef TSF_PLATFORM_PROVIDER_ADAPTATIONS
