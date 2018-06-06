import path from 'path'

import defaultWebpackConfig from '@phenomic/plugin-bundler-webpack/lib/webpack.config.js'

module.exports = config => {
  const webpackConfig = defaultWebpackConfig(config)
  return Object.assign({}, webpackConfig, {
    module: {
      rules: [
        // react-native-web
        {
          test: /\.js$/,
          include: [
            path.resolve('lib'),
            path.resolve('src'),
            path.resolve('node_modules', 'bs-react-native'),
            path.resolve('node_modules', 'react-native-web')
          ],
          loader: require.resolve('babel-loader'),
          options: {
            babelrc: false,
            plugins: [[require.resolve('babel-plugin-react-native-web'), { module: true }]]
          }
        }
      ].concat(webpackConfig.module.rules)
    }
  })
}
