module Link = Gatsby.Link;

module MyBanner = {
  [@bs.module "./MyBanner.js"] [@react.component]
  external make: (~message: string) => React.element = "default";
};

// module PreviewCompatibleImage = {
//   [@bs.module "./MyBanner.js"] [@react.component]
//   external make: (~childImageSharp : object, ~style : object) => React.element = "default";
// }

// module MyBanner = {
//   [@react.component] [@bs.module]
//   external make: (~message: string) => React.element = "./MyBanner";
// }
// [@react.component] [@bs.module]
// import React, { useState } from 'react'
// import PropTypes from 'prop-types'

// import { Link, graphql, StaticQuery } from 'gatsby'
// import PreviewCompatibleImage from './PreviewCompatibleImage'
// [@bs.module "./PreviewCompatibleImage.js"]

// function FaveTile(props) {
//   //TODO: tile stays same size on state change
//   const [isImage, setIsImage] = useState(true);

//   return (
//       <div className="is-parent column is-6">
//           <article
// className={`blog-list-item tile is-child box notification ${
//               props.post.frontmatter.featuredpost ? 'is-featured' : ''

//             }`}
//             onMouseEnter={() => setIsImage(false)}
//             onMouseLeave={() => setIsImage(true)}
//           >

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
type tileState =
  | Words
  | Image;

[@react.component]
let make = (~post) => {
  let (tileState, setTileState) = React.useState(_ => Image);
  let renderImageJsx = () => {
    <div>
      <header>
        <p className="post-meta">
          <Link
            className="title has-text-primary is-size-4"
            _to=post##fields##slug>
            {React.string(post##frontmatter##title)}
          </Link>
          <span className="subtitle is-size-5 is-block">
            {React.string(post##frontmatter##date)}
          </span>
        </p>
      </header>
      // ) : null}
      //   </div>
      //     />
      //       }}
      //         alt: "featured image thumbnail for post ${props.post.frontmatter.title}",
      //         image: post##frontmatter##featuredimage,
      //       imageInfo={{
      //     <PreviewCompatibleImage
      //   <div className="featured-thumbnail">
      // {post##frontmatter##featuredimage ? (
      // <MyBanner message="lol" />
      <p>
        {post##excerpt}
        <br />
        <br />
        <Link className="button" _to={post##fields##slug}>
          {React.string("Keep Reading")}
        </Link>
      </p>
    </div>;
  };
  let renderWordsJsx = () => {
    <div> {React.string("help")} </div>;
  };

  <div className="is-parent column is-6">
    <article
      className="blog-list-item tile is-child box notification ${
      post##frontmatter##featuredpost ? 'is-featured' : ''
      }"
      onMouseEnter={_ => setTileState(_ => Words)}
      onMouseLeave={_ => setTileState(_ => Image)}>
      {switch (tileState) {
       | Words => renderWordsJsx()
       | Image => renderImageJsx()
       }}
    </article>
  </div>;
};

// <button> {React.string("e added!")} </button>

// <header>
// {props.post.frontmatter.featuredimage ? (
//         <div className="featured-thumbnail">
//           <PreviewCompatibleImage
//             imageInfo={{
//               image: props.post.frontmatter.featuredimage,
//               alt: `featured image thumbnail for post ${props.post.frontmatter.title}`,
//             }}
//           />
//         </div>
//       ) : null}
//       <p className="post-meta">
// if (isImage) {
//   <div>
//     <header>
//       <p className="post-meta">
//         <Link
//           className="title has-text-primary is-size-4"
//           _to=post##fields##slug>
//           {React.string(post##frontmatter##title)}
//         </Link>
//         <span className="subtitle is-size-5 is-block">
//           {React.string(post##frontmatter##date)}
//         </span>
//       </p>
//     </header>
//     // ) : null}
//     //   </div>
//     //     />
//     //       }}
//     //         alt: "featured image thumbnail for post ${props.post.frontmatter.title}",
//     //         image: post##frontmatter##featuredimage,
//     //       imageInfo={{
//     //     <PreviewCompatibleImage
//     //   <div className="featured-thumbnail">
//     // {post##frontmatter##featuredimage ? (
//     <MyBanner message="lol" />
//     <p>
//       {post##excerpt}
//       <br />
//       <br />
//       <Link className="button" _to={post##fields##slug}>
//         {React.string("Keep Reading")}
//       </Link>
//     </p>
//   </div>;
// } else {
//   <div> {React.string("help")} </div>;
// };

// {isImage && (
//   <div>
//     <header>
//       {props.post.frontmatter.featuredimage ? (
//         <div className="featured-thumbnail">
//           <PreviewCompatibleImage
//             imageInfo={{
//               image: props.post.frontmatter.featuredimage,
//               alt: `featured image thumbnail for post ${props.post.frontmatter.title}`,
//             }}
//           />
//         </div>
//       ) : null}
//       <p className="post-meta">
//         <Link
//           className="title has-text-primary is-size-4"
//           to={props.post.fields.slug}
//         >
//           {props.post.frontmatter.title}
//         </Link>
//         <span> &bull; </span>
//         <span className="subtitle is-size-5 is-block">
//           {props.post.frontmatter.date}
//         </span>
//       </p>
//     </header>
//     <p>
//       {props.post.excerpt}
//       <br />
//       <br />
//       <Link className="button" to={props.post.fields.slug}>
//         Keep Reading →
//       </Link>
//     </p>
//   </div>
// )}

let default = make;