//@import url(https://fonts.googleapis.com/css?family=Lato:700);

// -- vars
$bg-color: #34495e;
$default-size: 1em;
$label-font-size: $default-size / 4;
$label-font-size-redo: $default-size * 4;

// -- mixins
@mixin size($width, $height) {
  height: $height;
  width: $width;
}

@mixin draw-progress($progress, $color) {
  .pie {
    .half-circle {
      border-color: $color;
    }

    .left-side {
      transform: rotate($progress * 3.6deg);
    }

    @if $progress <= 50 {
      .right-side {
        display: none;
      }
    } @else {
      clip: rect(auto, auto, auto, auto);

      .right-side {
        transform: rotate(180deg);
      }
    }
  }
}

@mixin draw-progress--solid($progress, $color, $bg-color) {
  background: linear-gradient(to right, $color 50%, $bg-color 50%);
  
  &:before {
    @if $progress <= 50 {
      background: $bg-color;
      transform: rotate((100 - (50 - $progress)) / 100 * 360deg * -1);
    } @else {
      background: $color;
      transform: rotate((100 - $progress) / 100 * 360deg);
    }
  }
}

// -- selectors
*,
*:before,
*:after {
  box-sizing: border-box;
}

html,
body {
  background: #ecf0f1;
  color: #444;
  font-family: 'Lato', Tahoma, Geneva, sans-serif;
  font-size: 16px;
  padding: 10px;
}

.set-size {
  font-size: 10em;
}

.charts-container {
  &:after {
    clear: both;
    content: '';
    display: table;
  }
}

.pie-wrapper {
  @include size($default-size, $default-size);
  float: left;
  margin: 15px;
  position: relative;
  
  &:nth-child(3n + 1) {
    clear: both;
  }

  .pie {
    @include size(100%, 100%);
    clip: rect(0, $default-size, $default-size, $default-size / 2);
    left: 0;
    position: absolute;
    top: 0;

    .half-circle {
      @include size(100%, 100%);
      border: ($default-size / 10) solid #3498db;
      border-radius: 50%;
      clip: rect(0, $default-size / 2, $default-size, 0);
      left: 0;
      position: absolute;
      top: 0;
    }
  }

  .label {
    background: $bg-color;
    border-radius: 50%;
    bottom: $label-font-size-redo / 10;
    color: #ecf0f1;
    cursor: default;
    display: block;
    font-size: $label-font-size;
    left: $label-font-size-redo / 10;
    line-height: $label-font-size-redo * .70;
    position: absolute;
    right: $label-font-size-redo / 10;
    text-align: center;
    top: $label-font-size-redo / 10;

    .smaller {
      color: #bdc3c7;
      font-size: .45em;
      padding-bottom: 20px;
      vertical-align: super;
    }
  }

  .shadow {
    @include size(100%, 100%);
    border: $default-size / 10 solid #bdc3c7;
    border-radius: 50%;
  }

  &.style-2 {
    .label {
      background: none;
      color: #7f8c8d;

      .smaller {
        color: #bdc3c7;
      }
    }
  }

  &.progress-30 {
    @include draw-progress(30, #3498db);
  }

  &.progress-60 {
    @include draw-progress(60, #9b59b6);
  }

  &.progress-90 {
    @include draw-progress(90, #e67e22);
  }

  &.progress-45 {
    @include draw-progress(45, #1abc9c);
  }

  &.progress-75 {
    @include draw-progress(75, #8e44ad);
  }

  &.progress-95 {
    @include draw-progress(95, #e74c3c);
  }
}

.pie-wrapper--solid {
  border-radius: 50%;
  overflow: hidden;

  &:before {
    border-radius: 0 100% 100% 0 / 50%;
    content: '';
    display: block;
    height: 100%;
    margin-left: 50%;
    transform-origin: left;
  }
  
  .label {
    background: transparent;
  }
  
  &.progress-65 {
    @include draw-progress--solid(65, #e67e22, $bg-color);
  }
  
  &.progress-25 {
    @include draw-progress--solid(25, #9b59b6, $bg-color);
  }
  
  &.progress-88 {
    @include draw-progress--solid(88, #3498db, $bg-color);
  }
}