import React from 'react'
import PropTypes from 'prop-types'
import { Link, graphql, StaticQuery } from 'gatsby'
import PreviewCompatibleImage from './PreviewCompatibleImage'


class FaveTile extends React.Component {
    render() {
        return (
            <div className="is-parent column is-6">
                <article
                  className={`blog-list-item tile is-child box notification ${
                    this.props.post.frontmatter.featuredpost ? 'is-featured' : ''
                  }`}
                >
                  <header>
                    {this.props.post.frontmatter.featuredimage ? (
                      <div className="featured-thumbnail">
                        <PreviewCompatibleImage
                          imageInfo={{
                            image: this.props.post.frontmatter.featuredimage,
                            alt: `featured image thumbnail for post ${this.props.post.frontmatter.title}`,
                          }}
                        />
                      </div>
                    ) : null}
                    <p className="post-meta">
                      <Link
                        className="title has-text-primary is-size-4"
                        to={this.props.post.fields.slug}
                      >
                        {this.props.post.frontmatter.title}
                      </Link>
                      <span> &bull; </span>
                      <span className="subtitle is-size-5 is-block">
                        {this.props.post.frontmatter.date}
                      </span>
                    </p>
                  </header>
                  <p>
                    {this.props.post.excerpt}
                    <br />
                    <br />
                    <Link className="button" to={this.props.post.fields.slug}>
                      Keep Reading →
                    </Link>
                  </p>
                </article>
              </div>
        )
    }
}
export default FaveTile