const path = require('path');
const outputDir = path.join(__dirname, 'example/build');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  mode: isProd ? 'production' : 'development',
  entry: { bsReactFela: './example/bs-react-fela/index.bs.js' },
  output: {
    path: outputDir,
    publicPath: outputDir,
    filename: '[name].js'
  }
};
