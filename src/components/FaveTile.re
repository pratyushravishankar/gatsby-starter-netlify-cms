module Link = Gatsby.Link;

type imageInfoString = {
  image: option(string),
  alt: string,
};

module PreviewCompatibleImage = {
  [@bs.module "./PreviewCompatibleImage.js"] [@react.component]
  external make: (~imageInfo: imageInfoString) => React.element = "default";
};

type tileState =
  | Words
  | Image;

[@react.component]
let make = (~post) => {
  let (tileState, setTileState) = React.useState(_ => Image);

  let possNullImg = Js.Nullable.toOption(post##frontmatter##featuredimage);
  let renderImageJsx = () => {
    <div>
      {switch (possNullImg) {
       | None => React.null
       | Some(img) =>
         <div className="featured-thumbnail">
           <PreviewCompatibleImage
             imageInfo={
               image: img,
               alt: "featured image thumbnail for post ${post##frontmatter##title}",
             }
           />
         </div>
       }}
    </div>;
  };
  let renderWordsJsx = () => {
    <div>
      <header>
        {switch (possNullImg) {
         | None => React.null
         | Some(img) =>
           <div className="featured-thumbnail">
             <PreviewCompatibleImage
               imageInfo={
                 image: img,
                 alt: "featured image thumbnail for post ${post##frontmatter##title}",
               }
             />
           </div>
         }}
        <p className="post-meta">
          <Link
            className="title has-text-primary is-size-4"
            _to=post##fields##slug>
            {React.string(post##frontmatter##title)}
          </Link>
          <span />
          <span className="subtitle is-size-5 is-block">
            {React.string(post##frontmatter##date)}
          </span>
        </p>
      </header>
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

let default = make;