import { ListItemButton, ListItemText } from '@mui/material';
import { Box } from '@mui/system';
import React from 'react';
import { Link } from "react-router-dom";

const linkStyle = {
    all: "unset"
}

function Nav(props) {
  return (
    <React.Fragment>
        <Box display="flex" sx={{ bgcolor: "lightGray", p:1}}>
            <Link to="/alPreTem" style={linkStyle}>
                <ListItemButton>
                    <ListItemText primary="Pression Altitude Temperature" />
                </ListItemButton>
            </Link>
            <Link to="/" style={linkStyle}>
                <ListItemButton>
                    <ListItemText primary="Acceleration Vitesse" />
                </ListItemButton>
            </Link>
        </Box>
        <Box sx={{p: 2}}>
            { props.children }
        </Box>
    </React.Fragment>
  );
}

export default Nav;