import React, { Component } from "react";
import Helmet from "react-helmet";
import { About } from "../components/About/";
import Drawer from "../layouts/Drawer/Drawer";
import SiteWrapper from "../layouts/SiteWrapper/SiteWrapper";
import MainHeader from "../layouts/MainHeader/MainHeader";
import MainNav from "../layouts/MainNav/MainNav";
import BlogLogo from "../components/BlogLogo/BlogLogo";
import Navigation from "../components/Navigation/Navigation";
import MenuButton from "../components/MenuButton/MenuButton";
import config from "../../data/SiteConfig";

class AboutPage extends Component {
  state = {
    menuOpen: false
  };

  handleOnClick = evt => {
    evt.stopPropagation();
    if (this.state.menuOpen) {
      this.closeMenu();
    } else {
      this.openMenu();
    }
  };

  handleOnClose = evt => {
    evt.stopPropagation();
    this.closeMenu();
  };

  openMenu = () => {
    this.setState({ menuOpen: true });
  };

  closeMenu = () => {
    this.setState({ menuOpen: false });
  };

  render() {
    return (
      <Drawer className="author-template" isOpen={this.state.menuOpen}>
        <div className="about-container">
          <Helmet>
            <title>{`À propos | ${config.siteTitle}`}</title>
            <link
              href="https://fonts.googleapis.com/css?family=Ubuntu:300,400,700"
              rel="stylesheet"
            />
          </Helmet>
          <Navigation config={config} onClose={this.handleOnClose} />
          <SiteWrapper>
            <MainHeader className="author-head" cover="/images/blog-cover.jpg">
              <MainNav>
                <BlogLogo logo={config.siteLogo} title={config.siteTitle} />
                <MenuButton
                  navigation={config.siteNavigation}
                  onClick={this.handleOnClick}
                />
              </MainNav>
            </MainHeader>
            <About />
          </SiteWrapper>
        </div>
      </Drawer>
    );
  }
}

export default AboutPage;
