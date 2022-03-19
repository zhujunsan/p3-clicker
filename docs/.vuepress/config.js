module.exports = {
  title: 'P3 Clicker',
  description: 'P3 Clicker module for GPD Pocket 3',
  plugins: [
    '@vuepress/active-header-links',
    '@vuepress/back-to-top',
    '@vuepress/last-updated',
    'vuepress-plugin-medium-zoom',
    'vuepress-plugin-smooth-scroll'
  ],
  markdown: {
    toc: {
      includeLevel:[1, 2, 3, 4]
    }
  }
}