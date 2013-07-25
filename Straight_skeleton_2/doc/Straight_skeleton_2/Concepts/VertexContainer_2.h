/*!
\ingroup PkgStraightSkeleton2Concepts
\cgalConcept

### Introduction ###

A model for the `VertexContainer_2` concept defines the requirements for a resizable container of 2D points. It is used to output the offset polygons generated by the `Polygon_offset_builder_2<Ssds,Gt,Container>` class. 

\cgalHasModel CGAL::Polygon_2 
\cgalHasModel Any \a standard `BackInsertionSequence`, such as std::vector, std::list or std::deque, with a `value_type` being a model of the `Kernel::Point_2` concept. 

*/

class VertexContainer_2 {
public:

/// \name Types 
/// @{

/*!
A 2D point type used to represent a vertex. Must be a model of the `Kernel::Point_2` concept 
*/ 
typedef unspecified_type Point_2; 

/*!
A unsigned integral type that can represent the number of vertices in the container. 
*/ 
typedef unspecified_type size_type; 

/// @} 

/// \name Creation 
/// @{

/*!
Default constructor 
*/ 
VertexContainer_2(); 

/*!
Returns the number of vertices in the container. 
*/ 
size_type size() const; 

/*!
Adds the vertex v to the container, resizing its capacity if required. 
*/ 
void push_back( Point_2 const& v) const; 

/// @}

}; /* end VertexContainer_2 */
