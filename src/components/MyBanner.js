var ReactDOM = require('react-dom');
var React = require('react');

// var MyBanner = function (props) {

//   // return React.createElement('div', null,
//   //   'Here\'s the message from the owner: ' + props.message
//   // );

//   return (
//     <button> {this.props.message} </button>
//   )
// };



const MyBanner = class extends React.Component {
  render() {
    // const imageStyle = { borderRadius: '5px' }
    // const { alt = '', childImageSharp, image } = imageInfo
    return (
      <button> {this.props.message} </button>
    )
  }
}

export default MyBanner


// module.exports = MyBanner;