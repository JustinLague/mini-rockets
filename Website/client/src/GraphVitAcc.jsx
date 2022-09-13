import React from 'react';
import Plot from 'react-plotly.js';

function GraphVitAcc() {
  return (
    <React.Fragment>
        <Plot
            data={[{
                x: [1, 2, 3],
                y: [2, 6, 3],
                type: 'scatter',
                mode: 'lines+markers',
                marker: {color: 'red'},
            },]}
            layout={{title: 'Acceleration et Vitesse'} }
        />
    </React.Fragment>
  );
}

export default GraphVitAcc;
