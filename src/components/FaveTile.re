
// import React, { useState } from 'react'
// import PropTypes from 'prop-types'

// import { Link, graphql, StaticQuery } from 'gatsby'
// import PreviewCompatibleImage from './PreviewCompatibleImage'

// function FaveTile(props) {
//   //TODO: tile stays same size on state change
//   const [isImage, setIsImage] = useState(true);

//   return (
//       <div className="is-parent column is-6">
//           <article
//             className={`blog-list-item tile is-child box notification ${
//               props.post.frontmatter.featuredpost ? 'is-featured' : ''

//             }`}
//             onMouseEnter={() => setIsImage(false)}
//             onMouseLeave={() => setIsImage(true)}
//           >
//             {isImage && (
//               <div>
//                 <header>
//                   {props.post.frontmatter.featuredimage ? (
//                     <div className="featured-thumbnail">
//                       <PreviewCompatibleImage
//                         imageInfo={{
//                           image: props.post.frontmatter.featuredimage,
//                           alt: `featured image thumbnail for post ${props.post.frontmatter.title}`,
//                         }}
//                       />
//                     </div>
//                   ) : null}
//                   <p className="post-meta">
//                     <Link
//                       className="title has-text-primary is-size-4"
//                       to={props.post.fields.slug}
//                     >
//                       {props.post.frontmatter.title}
//                     </Link>
//                     <span> &bull; </span>
//                     <span className="subtitle is-size-5 is-block">
//                       {props.post.frontmatter.date}
//                     </span>
//                   </p>
//                 </header>
//                 <p>
//                   {props.post.excerpt}
//                   <br />
//                   <br />
//                   <Link className="button" to={props.post.fields.slug}>
//                     Keep Reading →
//                   </Link>
//                 </p>
//               </div>
//             )}

//             {!isImage && (
//               <div>
//                 no image displayed
//               </div>
//             )}
//               </article>

//         </div>
//   )
// }

// export default FaveTile









  [@react.component]
  let make = () => {
    <button> {React.string("Hello!")} </button>
  };



  let default = make;