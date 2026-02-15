/* 
 Declaration of GameObjects and their properties.
 
 Default GameObject Layout is:
- RenderingMesh
    * Sprite
    * Model
 
- PhysicsMesh
    * 2D
    * 3D
 
- Type
    * Group - Special type of game object that can unite several objects in single one with shared properties.
    * Static - Object type for static objects within game (Map, UI)
    * Dynamic - Objects with dynmic changes in properties
    * Camera - Rendering objects that has seversl sybtypes (Perspective, Orthographic, Isometric)
    * Audio - Objest for audio properties defenition within scene (Could be physicaly limited within World)
    * Light - Rendering object that contains data and atributes for renderer, could provide different output based on shader. Has 2D and 3D subtypes
*/
